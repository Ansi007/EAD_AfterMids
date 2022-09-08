using Cookie.Models;
using Microsoft.AspNetCore.Mvc;
using System.Diagnostics;

namespace Cookie.Controllers
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
            //COOOOOOOKIE 
            if (!HttpContext.Request.Cookies.ContainsKey("FIRST_REQUEST")) {
                CookieOptions cookieOptions = new CookieOptions();
                cookieOptions.Expires = DateTime.Now.AddDays(1);
                HttpContext.Response.Cookies.Append("FIRST_REQUEST", DateTime.Now.ToString(), cookieOptions);
            }
            else
            {
                DateTime LastDate = DateTime.Parse(HttpContext.Request.Cookies["FIRST_REQUEST"]);
                string data = "WELCOME BACK BRO! LAST TIME YOU VISITED ON: " + LastDate;
                //HttpContext.Response.Cookies.Append("FIRST_REQUEST", DateTime.Now.ToString());
                HttpContext.Response.Cookies.Delete("FIRST_REQUEST");

                //ONLINE LECTURE # 56
                return View("Index", data);
            }
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
    }
}