using DependencyInjection.Models.Interfaces;

namespace DependencyInjection.Models.Repositories
{
    public class EmployeeRepository : IEmployeeRepository
    {
        public List<Employee> GetAll()
        {
            List<Employee> employees = new List<Employee>();
            employees.Add(new Employee { ID = "1", Name = "Anns" });
            employees.Add(new Employee { ID = "2", Name = "Shahbaz" });
            return employees;
        }
    }
}
