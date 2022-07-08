/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Model.Tiles;

/**
 *
 * @author nicktz4
 */


public class MosaicTile extends FindingTile {
	/**
	 * is the color of the MosaicTile
	 */
	private Colors color;	
	
	/**
	 * Constructor of MosaicTile
	 * <b>Precondition:</b> State value must be valid
	 * <b>Postcondition:</b> Succesfully creates a MosaicTile 
	 * @param state is the state of the Tile 
	 * @param color is the color of the Mosaic 
	 */
	public MosaicTile( int state,Colors color) {
		super("Mosaic", state);
		this.color = color;
	}
	/**
	 * <b>Accessor:</b> returns Mosaic's color
	 * <b>Postcondition:</b> Mosaic's color returned succesfully
	 * @return mosaic's color
	 */
	public Colors getColor() {
		return color;
	}
	
}
