struct Employee
{
    char name[100];
    double salary;
    Employee* boss;
};

Employee* findSuperBoss (Employee *e)
{
    if (e->boss == nullptr)
        return e;
    return findSuperBoss(e->boss);
}

Employee* findSuperBoss2 (Employee *e)
{
    while (e->boss != nullptr)
    {
        e = e->boss;
    }
    return e;
}