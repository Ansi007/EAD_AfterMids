$(document).ready(function () {
    $("#b1").click(function () {
        $.post("/Home/NewsPartialView", {name: "Data"}, function (result) {
            $("#PartialPlaceHolder").html(result);
        });
    });
});

$(document).ready(function () {
    $("#b2").click(function () {
        $("#PartialPlaceHolder").html("");
    });
});