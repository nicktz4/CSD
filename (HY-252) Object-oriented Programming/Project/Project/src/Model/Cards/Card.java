
package Model.Cards;

import Model.Tiles.Colors;

/**
 *
 * @author nicktz4
 */
public abstract class Card {
	private boolean used;
	protected String attribute;
	protected Colors cardHolder;

	/**
	 * Constructor.
	 * <b>Postcondition:</b> Creates a new  card with used=false 
	 * @param cardHolder is the holder of the card.Every player has a different (integer) id
	 */
	public Card(Colors cardHolder) {
		used = false;
		this.cardHolder = cardHolder;
	}
	/**
	 * <b>Observer:</b> checks if the card is available to use
	 * <b>Postcondition:</b> availability of card has been returned
	 * @return true if card is available,false otherwise
	 */
 	public boolean isAvailable() {
		return used;
	}	
	
	/**
	 *<b>Transformer:</b> sets the value of (variable) used true
	 * <b>Postcondition:</b> succesfully sets the value of (variable) used ,true
	 */
	public void setUsed() {
		used = true;
	}
	
	/**
	 * <b>Accessor:</b> it triggers the ability of the card
	 * <b>Precondition:</b> Card must not have been used.(variable) used to false;
	 * <b>Postcondition:</b> Succesfully triggers the cards ability.

	 */
	public void triggerAbility() {
		
	}	
		


	
	/**
	 * Returns the string representation of the card 
	 * <p><b>Postcondition:</b> The string representation of a card is returned</p>
     	 * @return The string representation of the card 
	 */
	 @Override
	public String toString() {
		return this.attribute.toString();
	}
}
