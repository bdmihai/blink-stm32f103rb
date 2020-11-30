import qbs

Project {
    name: "blink"
    minimumQbsVersion: "1.16"
    qbsSearchPaths: "../qbs"

    references: [
        "startup/startup.qbs",
        "linker/linker.qbs",
        "cmsis/cmsis.qbs",
        "hal/hal.qbs",
        "freertos/freertos.qbs",
        "app/app.qbs"
    ]
}


