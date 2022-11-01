
class ValidWordAbbr {

    /**
     * @param {string[]} dictionary
     */
    constructor(dictionary) {
        this.NO_FILL_ABBREVIATION_SLOT = "";
        this.SEVERAL_WORDS_WITH_SAME_ABBREVIATION = "*";
        this.abbreviationsToWords = new Map();//Map<string, string>

        for (let word of dictionary) {
            const abbreviation = this.createAbbreviation(word);
            if (this.abbreviationsToWords.has(abbreviation) && this.abbreviationsToWords.get(abbreviation) !== word) {
                this.abbreviationsToWords.set(abbreviation, this.SEVERAL_WORDS_WITH_SAME_ABBREVIATION);
                continue;
            }
            this.abbreviationsToWords.set(abbreviation, word);
        }
    }

    /** 
     * @param {string} word
     * @return {boolean}
     */
    isUnique(word) {
        const abbreviation = this.createAbbreviation(word);
        return !this.abbreviationsToWords.has(abbreviation) || this.abbreviationsToWords.get(abbreviation) === word;
    }

    /** 
     * @param {string} word
     * @return {string}
     */
    createAbbreviation(word) {
        let abbreviation = word.charAt(0);
        abbreviation += (word.length > 2 ? word.length - 2 : this.NO_FILL_ABBREVIATION_SLOT);
        abbreviation += (word.length > 1 ? word.charAt(word.length - 1) : this.NO_FILL_ABBREVIATION_SLOT);
        return abbreviation;
    }
}
