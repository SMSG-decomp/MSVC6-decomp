char __thiscall source_tracker_push(c1_source_tracker *tracker,int arg)

{
  uint uVar1;
  int iVar2;
  char *pcVar3;
  c1_source_tracker *pcVar4;
  
  g_source_tracker_depth = g_source_tracker_depth + 1;
  if (0x3ff < (uint)g_source_tracker_depth) {
    return '\0';
  }
  if (g_source_tracker_depth != 0) {
    pcVar4 = __2_YAPAXI_Z(0x14);
    if (pcVar4 == (c1_source_tracker *)0x0) {
      pcVar4 = (c1_source_tracker *)0x0;
    }
    else {
      pcVar4->iface_vtbl = &PTR__purecall_106548b0;
      pcVar4->signature = 0xffffffff;
      pcVar4->vtbl = (c1_vtbl_1065b190 *)&PTR_source_tracker_push_1065b190;
      pcVar4->iface_vtbl = &PTR_source_tracker_take_1065b184;
      pcVar4->signature = 0xffffffff;
      pcVar4->count = 0;
    }
    g_source_tracker_stack[g_source_tracker_depth] = pcVar4;
    uVar1 = tracker->signature;
    iVar2 = tracker->count;
    pcVar3 = tracker->mark;
    tracker->signature = pcVar4->signature;
    tracker->count = pcVar4->count;
    tracker->mark = pcVar4->mark;
    pcVar4 = g_source_tracker_stack[g_source_tracker_depth];
    pcVar4->mark = pcVar3;
    pcVar4->signature = uVar1;
    pcVar4->count = iVar2;
  }
  tracker->mark = (char *)(g_input_ptr + -1);
  return '\x01';
}

