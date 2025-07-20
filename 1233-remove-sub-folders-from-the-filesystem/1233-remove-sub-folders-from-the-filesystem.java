class Solution {
    public List<String> removeSubfolders(String[] folder) {
        Arrays.sort(folder);
        List<String> rootFolder = new ArrayList<>();
        rootFolder.add(folder[0]);

        for(int i = 1; i < folder.length; i++){
            String currFolder = folder[i];
            String lastFolder = rootFolder.get(rootFolder.size()-1) + '/';

            if(!currFolder.startsWith(lastFolder)){
                rootFolder.add(currFolder);
            }
        }

        return rootFolder;
    }
}