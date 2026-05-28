//Orizo klasi vet
public class Vet extends User {
  // Orizo
  // constructor("username","password","onoma","epitheto","email","tilefono")
  public Vet(String username, String pword, String name, String lastName, String email, String phone) {
    super(username, pword, name, lastName, email, phone);
  }

  // Orizo methodo me tin opoia o ktiniatros tha mporei na vazei nea xeirourgia
  // ston iatriko fakelo kathe zoou
  public void registerMedicalEntry(Animal animal, MedicalEntry entry) {
    if (animal != null && entry != null) {
      animal.getMedicalRecord().addEntry(entry);
    } else {
      System.out.println("Error : animal or procedure doesn't exist");
    }
  }

}
