
package Model.Cards;

import Model.Tiles.Colors;
import static Model.Tiles.Colors.BLUE;

/**
 *
 * @author nicktz4
 */
public class Digger extends Card {
	/**
	 * Constructor.
	 * <b>Postcondition:</b> Creates a new  Digger card  with attribute  
	 * @param cardHolder is the holder of the card
	 */
	public Digger(Colors cardHolder) {
		super(cardHolder);
		attribute="Pick up to 2 toles from the sorting area you chose earlier in your turn.\n";	
	}
}
