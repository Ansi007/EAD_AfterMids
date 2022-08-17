using Microsoft.AspNetCore.Mvc;
using Practice.Models;

namespace Practice.Controllers
{
    public class RoomController : Controller
    {
        [HttpPost]
        public IActionResult Index(Room r)
        {
            //Add in the DB
            return View(r);
        }
        [HttpGet]
        public IActionResult Index()
        {
            return View();
        }
    }
}
