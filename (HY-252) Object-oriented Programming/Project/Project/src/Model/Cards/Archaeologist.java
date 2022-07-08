
package Model.Cards;

import Model.Tiles.Colors;
import static Model.Tiles.Colors.GREEN;

/**
 *
 * @author nicktz4
 */
public class Archaeologist extends Card {
	/**
	 * Constructor.
	 * <b>Postcondition:</b> Creates a new  Archaeologist card  with attribute 
	 * @param cardHolder is the holder of the Card
	 */
	public Archaeologist(Colors cardHolder) {
		super(cardHolder);
	attribute = "Pick up to 2 tiles from any sorting area other than the one you chose earlier in your turn.\n";	
	}
}
