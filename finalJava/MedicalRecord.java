import java.util.Date;
import java.util.ArrayList;

public class MedicalRecord {
  // Arxikopoio ti lista me tis epemvaseis kathe zoou
  private ArrayList<MedicalEntry> entries;

  // Orizo constructor
  public MedicalRecord() {
    this.entries = new ArrayList<>();
  }

  // Methodos gia na prostheto ston fakelo epemvaseis
  public void addEntry(MedicalEntry entry) {
    this.entries.add(entry);
  }

  // Methodos gia na pairno ton fakelo
  public ArrayList<MedicalEntry> getEntries() {
    return entries;
  }

}
