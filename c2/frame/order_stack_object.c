void __fastcall order_stack_object(c2_symbol *obj,int32_t increment)

{
  int iVar1;
  c2_symbol *pcVar2;
  c2_symbol *pcVar3;
  c2_symbol *pcVar4;
  c2_symbol *after;
  int iVar5;
  
  if (obj->fe != (c2_fe_symbol *)0x0) {
    if (obj->fe == g_frame_eh_record) {
      return;
    }
    if ((g_opt_eh_enabled == 0) && (obj == g_eh_guard_local)) {
      return;
    }
  }
  iVar1 = obj->size;
  after = (c2_symbol *)0x0;
  for (pcVar2 = g_stack_object_order_head; pcVar2 != (c2_symbol *)0x0; pcVar2 = pcVar2->order_next)
  {
    if (iVar1 <= pcVar2->size) {
      if ((pcVar2 != (c2_symbol *)0x0) && (pcVar2->size == iVar1)) goto LAB_107351ce;
      break;
    }
    after = pcVar2;
  }
  goto LAB_107351e0;
  while( true ) {
    if (pcVar4 == obj) {
      iVar5 = (int)&((pcVar4->u34).source_links)->next_of_source + increment;
      (pcVar4->u34).refs = iVar5;
      for (; ((after != (c2_symbol *)0x0 && ((after->u34).refs < iVar5)) && (after->size == iVar1));
          after = (after->u30).order_prev) {
      }
      pcVar2 = (pcVar4->u30).order_prev;
      if (after == pcVar2) {
        return;
      }
      pcVar3 = pcVar4->order_next;
      if (pcVar3 != (c2_symbol *)0x0) {
        (pcVar3->u30).order_prev = pcVar2;
      }
      if (pcVar2 != (c2_symbol *)0x0) {
        pcVar2->order_next = pcVar3;
      }
      if (after != (c2_symbol *)0x0) {
        pcVar2 = after->order_next;
        if (pcVar2 != (c2_symbol *)0x0) {
          (pcVar2->u30).order_prev = pcVar4;
        }
        pcVar4->order_next = pcVar2;
        after->order_next = pcVar4;
        (pcVar4->u30).order_prev = after;
        return;
      }
      if (g_stack_object_order_head != (c2_symbol *)0x0) {
        (g_stack_object_order_head->u30).order_prev = pcVar4;
      }
      pcVar4->order_next = g_stack_object_order_head;
      (pcVar4->u30).order_prev = (c2_symbol *)0x0;
      g_stack_object_order_head = pcVar4;
      return;
    }
    pcVar2 = pcVar4->order_next;
    after = pcVar4;
    if (pcVar4->order_next == (c2_symbol *)0x0) break;
LAB_107351ce:
    pcVar4 = pcVar2;
    if (pcVar4->size != iVar1) break;
  }
LAB_107351e0:
  obj->order_next = (c2_symbol *)0x0;
  (obj->u30).order_prev = (c2_symbol *)0x0;
  (obj->u34).refs = increment;
  insert_stack_object_after(after,obj);
  g_stack_object_count = g_stack_object_count + 1;
  return;
}

