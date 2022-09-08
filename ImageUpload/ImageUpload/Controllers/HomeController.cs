using ImageUpload.Models;
using Microsoft.AspNetCore.Mvc;
using System.Diagnostics;
using Microsoft.AspNetCore.Hosting;
using System.IO;

namespace ImageUpload.Controllers
{
    public class HomeController : Controller
    {
        List<IFormFile> profilePictures;
        private readonly IWebHostEnvironment _env;
        private readonly ILogger<HomeController> _logger;

        public HomeController(ILogger<HomeController> logger, IWebHostEnvironment env)
        {
            _logger = logger;
            _env = env;
        }

        public HomeController(IWebHostEnvironment env)
        {
            _env = env;
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

        public IActionResult ImageUpload(IFormFile profileImage)
        {
            string webRootPath = _env.WebRootPath;
            string path = Path.Combine(webRootPath, "img");

            if (!Directory.Exists(path))
            {
                Directory.CreateDirectory(path);
            }
/*            using (FileStream stream = new FileStream(Path.Combine(path, "ProfilePic.jpg"))
            {
                profileImage.CopyTo(stream);
            };*/
            return View("ProfilePictures", profilePictures);
        }
    }
}