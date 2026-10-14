char __thiscall source_tracker_pop(c1xx_source_tracker *tracker,int arg)

{
  c1xx_source_tracker *pcVar1;
  
  (*tracker->vtbl->source_tracker_accumulate)(tracker);
  if (g_source_tracker_depth != 0) {
    pcVar1 = g_source_tracker_stack[g_source_tracker_depth];
    (tracker->iface).signature = (pcVar1->iface).signature;
    (tracker->iface).count = (pcVar1->iface).count;
    (tracker->iface).mark = (pcVar1->iface).mark;
    __3_YAXPAX_Z(g_source_tracker_stack[g_source_tracker_depth]);
  }
  g_source_tracker_depth = g_source_tracker_depth + -1;
  return '\x01';
}

