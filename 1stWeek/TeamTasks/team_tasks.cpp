//
// Created by Акбар on 23.02.2020.
//
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
// Перечислимый тип для статуса задачи
enum class TaskStatus {
    NEW,          // новая
    IN_PROGRESS,  // в разработке
    TESTING,      // на тестировании
    DONE          // завершена
};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;

class TeamTasks {
public:
    // Получить статистику по статусам задач конкретного разработчика
    const TasksInfo& GetPersonTasksInfo(const string& person) const{
        return data.at(person);
    };

    // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
    void AddNewTask(const string& person){
        data[person][TaskStatus::NEW]++;
    };

    // Обновить статусы по данному количеству задач конкретного разработчика,
    // подробности см. ниже
    tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count){
        TasksInfo old=data[person];
        TasksInfo untouched=data[person];
        if(untouched[TaskStatus::NEW]==0){untouched.erase(TaskStatus::NEW);}
        if(untouched[TaskStatus::IN_PROGRESS]==0){untouched.erase(TaskStatus::IN_PROGRESS);}
        if(untouched[TaskStatus::TESTING]==0){untouched.erase(TaskStatus::TESTING);}
        untouched.erase(TaskStatus::DONE);
        TasksInfo updated;
        for(int i=0;i<old[TaskStatus::NEW];i++){
            if(task_count>0){
                task_count--;
                data[person][TaskStatus::NEW]--;
                untouched[TaskStatus::NEW]--;
                if(untouched[TaskStatus::NEW]==0){untouched.erase(TaskStatus::NEW);}
                data[person][TaskStatus::IN_PROGRESS]++;
                updated[TaskStatus::IN_PROGRESS]++;
            }
        }
        for(int i=0;i<old[TaskStatus::IN_PROGRESS];i++){
            if(task_count>0){
                task_count--;
                data[person][TaskStatus::IN_PROGRESS]--;
                untouched[TaskStatus::IN_PROGRESS]--;
                if(untouched[TaskStatus::IN_PROGRESS]==0){untouched.erase(TaskStatus::IN_PROGRESS);}
                data[person][TaskStatus::TESTING]++;
                updated[TaskStatus::TESTING]++;
            }
        }
        for(int i=0;i<old[TaskStatus::TESTING];i++){
            if(task_count>0){
                task_count--;
                data[person][TaskStatus::TESTING]--;
                untouched[TaskStatus::TESTING]--;
                if(untouched[TaskStatus::TESTING]==0){untouched.erase(TaskStatus::TESTING);}
                data[person][TaskStatus::DONE]++;
                updated[TaskStatus::DONE]++;
            }
        }
        return tie(updated,untouched);
    };
private:
    map<string,TasksInfo>data;
};
// Принимаем словарь по значению, чтобы иметь возможность
// обращаться к отсутствующим ключам с помощью [] и получать 0,
// не меняя при этом исходный словарь

void PrintTasksInfo(TasksInfo tasks_info) {
    cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
         ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
         ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
         ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

int main() {
    TeamTasks tasks;
    tasks.AddNewTask("Ilia");
    for (int i = 0; i < 3; ++i) {
        tasks.AddNewTask("Ivan");
    }
    cout << "Ilia's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
    cout << "Ivan's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));

    TasksInfo updated_tasks, untouched_tasks;

    tie(updated_tasks, untouched_tasks) =
            tasks.PerformPersonTasks("Ivan", 2);
    cout << "Updated Ivan's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: ";
    PrintTasksInfo(untouched_tasks);

    tie(updated_tasks, untouched_tasks) =
            tasks.PerformPersonTasks("Ivan", 2);
    cout << "Updated Ivan's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: ";
    PrintTasksInfo(untouched_tasks);

    return 0;
}
