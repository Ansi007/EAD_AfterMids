using Microsoft.AspNetCore.Mvc;

namespace Practice.ViewComponents
{
    public class RoomSummary : ViewComponent
    {
        public IViewComponentResult Invoke(string number, string size)
        {
            var data = new
            {
                number = number,
                size = size
            };

            return View(data);
        }
    }
}
