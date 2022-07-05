using Jquery.Models;
using Microsoft.AspNetCore.Mvc;
using System.Diagnostics;

namespace Jquery.Controllers
{
    public class HomeController : Controller
    {
        private readonly ILogger<HomeController> _logger;

        public HomeController(ILogger<HomeController> logger)
        {
            _logger = logger;
        }

        public IActionResult Index()
        {
            return View();
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

        public PartialViewResult NewsPartialView(string name)
        {
            Student s = new Student();
            var rollNo = "BSEF19M007";
            s.Name = name;
            s.RollNo = rollNo;
            return PartialView("NewsPartialView",s);
        }

    }
}