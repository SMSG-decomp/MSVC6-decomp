char __thiscall mre_note_class_records(c1_mre_tracker *tracker,c1_symbol *cls)

{
  char cVar1;
  int iVar2;
  
  if (tracker->current->tracked == '\0') {
    cVar1 = '\x02';
  }
  else {
    cVar1 = tracker->busy != '\0';
  }
  if (cVar1 == '\x01') {
    mre_note_queue_push(&tracker->pending,3,cls,(void *)0x0);
  }
  else if (cVar1 != '\x02') {
    tracker->busy = '\x01';
    iVar2 = mre_class_ensure_records(cls);
    tracker->busy = '\0';
    if (iVar2 != 1) {
      if (iVar2 == 2) {
        return '\0';
      }
      if ((tracker->pending != (c1_mre_note *)0x0) && (tracker->draining == '\0')) {
        cVar1 = mre_note_queue_drain(tracker);
        return cVar1;
      }
    }
  }
  return '\x01';
}

