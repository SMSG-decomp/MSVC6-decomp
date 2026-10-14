char __thiscall source_tracker_pop(c1_source_tracker *tracker,int arg)

{
  c1_source_tracker *pcVar1;
  
  (*tracker->vtbl->source_tracker_accumulate)(tracker);
  if (g_source_tracker_depth != 0) {
    pcVar1 = g_source_tracker_stack[g_source_tracker_depth];
    tracker->signature = pcVar1->signature;
    tracker->count = pcVar1->count;
    tracker->mark = pcVar1->mark;
    __3_YAXPAX_Z(g_source_tracker_stack[g_source_tracker_depth]);
  }
  g_source_tracker_depth = g_source_tracker_depth + -1;
  return '\x01';
}

