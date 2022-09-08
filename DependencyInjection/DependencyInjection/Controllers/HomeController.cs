using DependencyInjection.Models;
using Microsoft.AspNetCore.Mvc;
using System.Diagnostics;
using DependencyInjection.Models.Interfaces;

namespace DependencyInjection.Controllers
{
    public class HomeController : Controller
    {
        private readonly ILogger<HomeController> _logger;
        private readonly IEmployeeRepository _employeeRepository;
        public HomeController(ILogger<HomeController> logger, IEmployeeRepository e)
        {
            _logger = logger;
            _employeeRepository = e;
        }

        public IActionResult Index()
        {
            return View(_employeeRepository.GetAll());
        }

        public IActionResult Privacy()
        {
            return View();
        }

        [ResponseCache(Duration = 0, Location = ResponseCacheLocation.None, NoStore = true)]
        public IActionResult Error()
        {
            return View(new ErrorViewModel { RequestId = Activity.Current?.Id ?? HttpContext.TraceIdentifier });
        }
    }
}