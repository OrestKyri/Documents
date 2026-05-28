import java.util.Date;

public class Vaccination implements MedicalEntry {
  // Orizo ta pedia tis klasis
  private Date date;
  private String description;
  private Vet vet;

  // Orizo ton constructor(Date,"perigrafi",Vet)
  public Vaccination(Date date, String description, Vet vet) {
    this.date = date;
    this.description = description;
    this.vet = vet;
  }

  // Setters/Getters
  public Date getDate() {
    return date;
  }

  public void setDate(Date date) {
    this.date = date;
  }

  public String getEntryDescription() {
    return description;
  }
  // den exw setter giati mono o vet mporei na vazei xeirourgeia

  public Vet getVet() {
    return vet;
  }
  // den exw set giati mono o staffuser mporei na allazei

  // Iperfortono tin toString()
  public String toString() {
    return new String(
        "Vaccination {" + "\nDate : " + date + "\nDescription : " + description + "\nVet : " + vet + "}\n");
  }

}
