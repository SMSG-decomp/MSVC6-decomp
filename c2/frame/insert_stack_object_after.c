void __fastcall insert_stack_object_after(c2_symbol *after,c2_symbol *obj)

{
  c2_symbol *pcVar1;
  
  if (after != (c2_symbol *)0x0) {
    pcVar1 = after->order_next;
    if (pcVar1 != (c2_symbol *)0x0) {
      (pcVar1->u30).order_prev = obj;
    }
    obj->order_next = pcVar1;
    after->order_next = obj;
    (obj->u30).order_prev = after;
    return;
  }
  if (g_stack_object_order_head != (c2_symbol *)0x0) {
    (g_stack_object_order_head->u30).order_prev = obj;
  }
  obj->order_next = g_stack_object_order_head;
  (obj->u30).order_prev = (c2_symbol *)0x0;
  g_stack_object_order_head = obj;
  return;
}

