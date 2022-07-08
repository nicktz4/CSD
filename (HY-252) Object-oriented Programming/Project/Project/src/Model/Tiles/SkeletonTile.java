
package Model.Tiles;

/**
 *
 * @author nicktz4
 */
public class SkeletonTile extends FindingTile {
	/**
	 * the size of the skeleton
	 * valid Values:(LARGE,SMALL)
	 */
	private String SkeletonSize;
	/**
	 * the body of the Skeleton
	 * valid Values:(UPPER,LOWER)
	 */
	private String SkeletonBody;
	/**
	 * Constructor of SkeletonTile
	 * <b>Precondition:</b> State value must be valid,SkeletonSize value must be valid.
	 * <b>Postcondition:</b> Succesfully creates a SkeletonTile 
	 * @param skeletonSize is the skeleton's size of the SkeletonTile
	 * @param skeletonBody is the skeleton's body of the SkeletonTile
	 * @param state is the state of the SkeletonTile
	 * 
	 */
	public SkeletonTile(String skeletonSize,String skeletonBody, int state) {
		super("Skeleton", state);
		SkeletonSize = skeletonSize;
		SkeletonBody = skeletonBody;
		
	}
/**
 * <b>Accessor</b> returns the skeleton Size of the skeleton
 * <b>Postcondition</b>Successfully returns the skeleton size of the Skeleton tile
 * @return   a string with the SkeletonSize of the skeleton tile
 */
	public String getSkeletonSize() {
		return SkeletonSize;
	}	
	/**
 * <b>Accessor</b> returns the skeleton body of the skeleton
 * <b>Postcondition</b>Successfully returns the skeleton body of the Skeleton tile
 * @return   a string with the SkeletonBody of the skeleton tile
 */
	public String getSkeletonBody() {
		return SkeletonBody;
	}
	
}
