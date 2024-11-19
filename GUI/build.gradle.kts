plugins {
    id("java")
    application
}

group = "org.example"
version = "1.0-SNAPSHOT"

repositories {
    mavenCentral()
}

dependencies {
    testImplementation(platform("org.junit:junit-bom:5.10.0"))
    testImplementation("org.junit.jupiter:junit-jupiter")
    implementation("io.github.java-native:jssc:2.9.6")
}

application {
    mainClass.set("GameLauncher")
}


tasks.test {
    useJUnitPlatform()
}