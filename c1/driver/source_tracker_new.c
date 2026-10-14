char __cdecl source_tracker_new(char minimal_rebuild,void **object,void **iface)

{
  c1_source_tracker *tracker;
  
  if (minimal_rebuild == '\0') {
    tracker = __2_YAPAXI_Z(8);
    if (tracker != (c1_source_tracker *)0x0) {
      tracker->iface_vtbl = &PTR__purecall_106548b0;
      tracker->vtbl = (c1_vtbl_1065b190 *)&PTR_source_tracker_stub_true_0_10654898;
      tracker->iface_vtbl = &PTR_source_tracker_stub_iface_false_0_1065488c;
      goto LAB_10613eec;
    }
  }
  else {
    tracker = __2_YAPAXI_Z(0x14);
    if (tracker != (c1_source_tracker *)0x0) {
      tracker->iface_vtbl = &PTR__purecall_106548b0;
      tracker->signature = 0xffffffff;
      tracker->vtbl = (c1_vtbl_1065b190 *)&PTR_source_tracker_push_1065b190;
      tracker->iface_vtbl = &PTR_source_tracker_take_1065b184;
      tracker->signature = 0xffffffff;
      tracker->count = 0;
      goto LAB_10613eec;
    }
  }
  tracker = (c1_source_tracker *)0x0;
LAB_10613eec:
  *object = tracker;
  if (tracker != (c1_source_tracker *)0x0) {
    *iface = &tracker->iface_vtbl;
    return '\x01';
  }
  *iface = (void *)0x0;
  return '\x01';
}

