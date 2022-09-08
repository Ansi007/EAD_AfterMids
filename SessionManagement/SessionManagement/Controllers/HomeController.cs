using Microsoft.AspNetCore.Mvc;
using SessionManagement.Models;
using System.Diagnostics;

namespace SessionManagement.Controllers
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
            string data = String.Empty;
            if (HttpContext.Session.Keys.Contains("FIRST_REQUEST"))
            {
                string firstdata = HttpContext.Session.GetString("FIRST_REQUEST");
                data = "WELCOME BACK " + firstdata;
            }
            else
            {
                data = System.DateTime.Now.ToString();
                HttpContext.Session.SetString("FIRST_REQUEST", data);
            }
            return View("Index", data);
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