using AcidEngine;

public class Sign : GameObject {

	public string info = "";
	
	public Sign() {
		sprite.SetTexture("Assets/images/spritesheetsigns.png");
		sprite.SetID(1);
		physics.SetColliderEnabled(true);
	}
	
	public Start() {
		
	}

	public Update() {
		
	}
	
	public Click() {
		Game.ShowPopup(info);
	}

};