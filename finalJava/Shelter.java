import java.util.ArrayList;
import java.util.Objects;

public class Shelter {
  // Plirofories shelter
  private static String name = "Gatia kai Skilia";
  private static String address = "Peiraias";
  private static String phone = "22222222";

  // Arxikopoio tis listes me tous xristes,ta zoa kai tis aitiseis
  public static ArrayList<User> users = new ArrayList<User>();

  static {

    users.add(new Adopter("mfilip", "mfx", "Michael", "Filippakis", "mfilip@unipi.gr", "22222223"));
    users.add(new Adopter("amenixtas", "javamono", "Apostolos", "Menixtas", "amenixtas@unipi.gr", "22222232"));
    users.add(new Adopter("meliones", "basi3.5", "Apostolos", "Milionis", "ameliones@unipi.gr", "32222222"));
    users.add(new Vet("alexios", "dem", "Alexandros", "Armeniakos", "armeniakos@unipi.", "111111"));
    users.add(new Vet("takis", "takaros", "Mitsaras", "Takaros", "dtakis@unipi.gr", "22222222"));
    users.add(new ShelterStaff("orestios", "orest", "Orestis", "Kyri", "orestkyri@gmail.com", "6947626657"));
  }

  public static ArrayList<Animal> animals = new ArrayList<Animal>();
  static {

    animals.add("terror139", "Tromos", 8, "Pitbull", DOG);
    animals.add("katastrofeas999", "Katastrofeas", 9, "Mia katastrofi", CAT);
    animals.add("prigkipisa1010", "Prigkipisa", 10, "Cane Corso", DOG);
    animals.add("polly555", "Polly", 5, "Ena pouli", BIRD);
  }
  public static ArrayList<AdoptionApplication> applications = new ArrayList<AdoptionApplication>();

  public String toString() {
    return new String(
        "Shelter { " + "\nName : " + name + "\nAddress : " + address + "\nPhone number : " + phone + "}\n");
  }

  // Getters ton static pedion
  public static String getShelterName() {
    return name;
  }

  public static String getShelterAddress() {
    return address;
  }

  public static String getShelterPhone() {
    return phone;
  }

  // Methodos gia na prostheso user
  public static void addUser(User newUser) {
    for (int i = 0; i < users.size(); i++) {
      if (Objects.equals(users.get(i).getUsername(), newUser.getUsername())) {
        System.out.println("User already exists");
      } else {
        users.add(newUser);
      }
    }
  }

  // Methodos gia na svino users
  public static void deleteUser(String username) {
    for (int i = 0; i < users.size(); i++) {
      // Sigkrino ta username gia na vro ton xristi
      if (Objects.equals(users.get(i).getUsername(), username)) {
        users.remove(i);
        i--;// Meiono to i giati i lista mikrine kata 1
      } else {
        continue;
      }
    }
  }

  public static void addAnimal(Animal newAnimal) {
    for (int i = 0; i < animals.size(); i++) {
      if (Objects.equals(animals.get(i).getId(), newAnimal.getId())) {
        System.out.println("Animal already exists");
      } else {
        animals.add(newAnimal);
      }
    }

  }

  // Methodos gia na sbino zoa
  public static void deleteAnimal(String animalID) {
    for (int i = 0; i < animals.size(); i++) {
      if (Objects.equals(animals.get(i).getId, animalID)) {
        animals.remove(i);
        i--;
      } else {
        continue;
      }
    }
  }

}
