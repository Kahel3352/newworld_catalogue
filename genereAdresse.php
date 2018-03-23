

<div class="md-form">
	<i class="fa fa-map-marker  prefix grey-text"></i>
	<input type="text" id="idAdresse" name="adresse" class="ui-autocomplete-input" autocomplete="off" value="" required>
	<label for="Form-Adresse">Adresse</label>
</div>

<div class="md-form">
  <i class="fa fa-road prefix grey-text"></i>
  <input type="text" id="idRue" name="street" value="" required placeholder="Rue">
</div>

<div class="md-form">
  <i class="fa fa-map-marker prefix grey-text"></i>
  <input type="text" id="idVille" name="city" value="" required placeholder="Ville">
</div>

<div class="md-form">
  <i class="fa fa-map-marker prefix grey-text"></i>
  <input type="text" id="idCP" name="cdepst" value="" required placeholder="Code Postal">
</div>

<div class="md-form">
  <input type="hidden" id="idLatitude" name="latitude" value="" required>
</div>

<div class="md-form">
  <input type="hidden" id="idLongitude" name="longitude" value="" required>
</div>

<script language="javascript">
$("#idAdresse").autocomplete(
{
  source : function (request, response)
  {
    $.ajax(
    {
      url: "https://api-adresse.data.gouv.fr/search/?limit=6",
      data:{q: request.term },
      dataType: "json",
      success: function (data) {
        response($.map(data.features, function (item){
          return { label: item.properties.label, postcode: item.properties.postcode,city: item.properties.city, value: item.properties.label, street: item.properties.street, name: item.properties.name, latitude: item.geometry.coordinates[1],longitude: item.geometry.coordinates[0] };
        }));
      }
    });
  },
  select: function (event,ui)
  {
   $('#idCP').val(ui.item.postcode);
    $('#idVille').val(ui.item.city);
    if(ui.item.street)
    $('#idRue').val(ui.item.street);
      else
    $('#idRue').val(ui.item.name);
      $("#idLatitude").val(ui.item.latitude);
      $("#idLongitude").val(ui.item.longitude);
  }
});
</script>



