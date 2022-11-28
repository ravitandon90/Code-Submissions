public boolean isAlienSorted(String[] words, String order) {
	var indexByChar = getIndexMap(order);
	
	for (var i = 0; i + 1 < words.length; i++) {
		var current = words[i];
		var next = words[i + 1];
		var matchCount = 0;
		var minLen = Math.min(current.length(), next.length());

		for (var j = 0; j < minLen; j++) {
			var index1 = indexByChar.get(current.charAt(j));
			var index2 = indexByChar.get(next.charAt(j));
			
			if (index1 < index2)
				break;
			if (index1 > index2)
				return false;
			matchCount++;
		}
		if (matchCount == minLen && current.length() > next.length())
			return false;
	}
	
	return true;
}

private Map<Character, Integer> getIndexMap(String order) {
	var indexByChar = new HashMap<Character, Integer>();
	for (var i = 0; i < order.length(); i++)
		indexByChar.put(order.charAt(i), i);
	return indexByChar;
}
