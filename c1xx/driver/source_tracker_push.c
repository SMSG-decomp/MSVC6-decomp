char __thiscall source_tracker_push(c1xx_source_tracker *tracker,int arg)

{
  c1_u32 cVar1;
  int iVar2;
  c1_u8 *pcVar3;
  c1xx_source_tracker *node;
  c1xx_source_tracker *node_2;
  
  g_source_tracker_depth = g_source_tracker_depth + 1;
  if (0x3ff < (uint)g_source_tracker_depth) {
    return '\0';
  }
  if (g_source_tracker_depth != 0) {
    node = __2_YAPAXI_Z(0x14);
    if (node == (c1xx_source_tracker *)0x0) {
      node = (c1xx_source_tracker *)0x0;
    }
    else {
      (node->iface).vtbl = (c1xx_source_tracker_iface_vtbl *)&PTR__purecall_104c5900;
      (node->iface).signature = 0xffffffff;
      node->vtbl = (c1xx_source_tracker_vtbl *)&PTR_source_tracker_push_104caea0;
      (node->iface).vtbl = (c1xx_source_tracker_iface_vtbl *)&PTR_source_tracker_take_104cae94;
      (node->iface).signature = 0xffffffff;
      (node->iface).count = 0;
    }
    g_source_tracker_stack[g_source_tracker_depth] = node;
    cVar1 = (tracker->iface).signature;
    iVar2 = (tracker->iface).count;
    pcVar3 = (tracker->iface).mark;
    (tracker->iface).signature = (node->iface).signature;
    (tracker->iface).count = (node->iface).count;
    (tracker->iface).mark = (node->iface).mark;
    node_2 = g_source_tracker_stack[g_source_tracker_depth];
    (node_2->iface).mark = pcVar3;
    (node_2->iface).signature = cVar1;
    (node_2->iface).count = iVar2;
  }
  (tracker->iface).mark = g_input_ptr + -1;
  return '\x01';
}

