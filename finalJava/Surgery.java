import java.util.Date;

public class Surgery implements MedicalEntry {
  // Orizo ta pedia
  private Date date;
  private String description;
  private Vet vet;

  // Orizo ton constructor
  public Surgery(Date date, String description, Vet vet) {
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
  // Den exw set giati mono o vet mporei na vazei xeirourgeia

  public Vet getVet() {
    return vet;
  }
  // Den exw setVet giati mono o StaffUser mporei na elegxei tous ktiniatrous

  public String toString() {
    return new String("Surgery {" + "\nDate : " + date + "\nDescription : " + description + "\nVet : " + vet + "}\n");
  }

}
