from threading import Lock


class DiningPhilosophers:
    def __init__(self):
        self._lock = Lock()

    def wantsToEat(self, index, *actions):
        with self._lock:
            for action in actions:
                action()
