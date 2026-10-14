char __cdecl source_tracker_new(char incremental,void **tracker,void **iface)

{
  void **tracker_obj;
  
  if (incremental == '\0') {
    tracker_obj = __2_YAPAXI_Z(8);
    if (tracker_obj != (void **)0x0) {
      tracker_obj[1] = &PTR__purecall_104c5900;
      *tracker_obj = &PTR_source_tracker_stub_true_0_104c58e8;
      tracker_obj[1] = &PTR_source_tracker_stub_iface_false_0_104c58dc;
      goto LAB_104466a0;
    }
  }
  else {
    tracker_obj = __2_YAPAXI_Z(0x14);
    if (tracker_obj != (void **)0x0) {
      tracker_obj[1] = &PTR__purecall_104c5900;
      tracker_obj[2] = (void *)0xffffffff;
      *tracker_obj = &PTR_source_tracker_push_104caea0;
      tracker_obj[1] = &PTR_source_tracker_take_104cae94;
      tracker_obj[2] = (void *)0xffffffff;
      tracker_obj[3] = (void *)0x0;
      goto LAB_104466a0;
    }
  }
  tracker_obj = (void **)0x0;
LAB_104466a0:
  *tracker = tracker_obj;
  if (tracker_obj != (void **)0x0) {
    *iface = tracker_obj + 1;
    return '\x01';
  }
  *iface = (void *)0x0;
  return '\x01';
}

