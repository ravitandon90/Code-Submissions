public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        List<List<Integer>> res = new ArrayList<>();
        LinkedList<Integer> list = new LinkedList<>();
        list.add(0);

        helper_backtracking(graph, 0, graph.length - 1, res, list);
        return res;
    }

    private void helper_backtracking(int[][] graph, int source, int target,
                        List<List<Integer>> res, LinkedList<Integer> list){
        if (source == target) {
            res.add(new ArrayList<>(list));
            return;
        }

        for (int neighbour: graph[source]) {
            list.add(neighbour);
            helper_backtracking(graph, neighbour, target, res, list);
            list.removeLast();
        }
    }
