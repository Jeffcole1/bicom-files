var names = ["name1", "name2", "name3", "name4", "name5"];
var email = ["email1@aol.com", "email2@yahoo.com", "email3@gmail.com", "email4@hotmail.com", "email5@somedomain.com"];
var tableLength = Math.min(names.length, email.length);
var index;
var nextRow, nextID, nextName, nextEmail, emailAnchor;

function createTable()
{
	var table = document.createElement("table");
	table.setAttribute("border", 1);
	
	var headerRow = table.insertRow(0);
	headerRow.className = "header";
	var idHeader = headerRow.insertCell(-1);
	idHeader.innerHTML = "ID";
	var nameHeader = headerRow.insertCell(-1);
	nameHeader.innerHTML = "Name";
	var emailHeader = headerRow.insertCell(-1);
	emailHeader.innerHTML = "E-mail";
	
	for (index = 0; index < tableLength; index++)
	{
		nextRow = table.insertRow(-1);
		if (index % 2 == 0)
			nextRow.className = "odd";
		else nextRow.className = "even";
		
		nextID = nextRow.insertCell(-1);
		nextID.innerHTML = index + 1;
		
		nextName = nextRow.insertCell(-1);
		nextName.innerHTML = names[index];
		
		nextEmail = nextRow.insertCell(-1);
		emailAnchor = document.createElement("a");
		emailAnchor.setAttribute("href", "mailto:" + email[index]);
		emailAnchor.innerHTML = email[index];
		nextEmail.appendChild(emailAnchor);
		
	}
	
	document.getElementsByTagName("body")[0].appendChild(table);
}

function styleTable()
{
	
}