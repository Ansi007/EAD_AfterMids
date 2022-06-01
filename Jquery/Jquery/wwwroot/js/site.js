$(document).ready(function () {
    $("#b1").click(function () {
        $.get("/Home/NewsPartialView", function (result) {
            $("#PartialPlaceHolder").html(result);
        });
    });
});

$(document).ready(function () {
    $("#b2").click(function () {
        $("#PartialPlaceHolder").html("");
    });
});