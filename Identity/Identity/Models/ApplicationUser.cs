﻿using Microsoft.AspNetCore.Identity;

namespace Identity.Models
{
    public class ApplicationUser : IdentityUser
    {
        public string Gender { get; set; }
    }
}
