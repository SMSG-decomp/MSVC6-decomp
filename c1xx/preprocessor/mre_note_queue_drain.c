char __thiscall mre_note_queue_drain(c1_mre_tracker *tracker)

{
  c1_mre_note *note;
  char local_1;
  
  tracker->draining = '\x01';
  note = tracker->pending;
  if (note != (c1_mre_note *)0x0) {
    tracker->pending = note->next;
  }
  local_1 = (char)((uint)tracker >> 0x18);
  while( true ) {
    switch(note->kind) {
    case 0:
      local_1 = mre_note_member_use(tracker,note->cls,note->member);
      break;
    case 1:
      local_1 = mre_note_class_layout_use(tracker,note->cls);
      break;
    case 2:
      local_1 = mre_note_class_use(tracker,note->cls);
      break;
    case 3:
      local_1 = mre_note_class_records(tracker,note->cls);
    }
    if (local_1 == '\0') break;
    note = tracker->pending;
    if (note == (c1_mre_note *)0x0) goto LAB_10495d64;
    tracker->pending = note->next;
  }
  tracker->pending = (c1_mre_note *)0x0;
LAB_10495d64:
  tracker->draining = '\0';
  return local_1;
}

