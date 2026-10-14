void __fastcall mark_parameters_used_in_body(c2_function *fn,void *params)

{
  c2_tuple *pcVar1;
  c2_operand *pcVar2;
  int iVar3;
  c2_symbol *storage;
  int local_8;
  
  param_list_contains((c2_symbol *)0x0,params,1);
  pcVar1 = fn->cfg->first->head;
  do {
    if (pcVar1 == (c2_tuple *)0x0) {
      return;
    }
    if (((pcVar1->flags & 1) != 0) && (pcVar1->kind != '\x17')) {
      local_8 = 2;
      do {
        if (local_8 == 2) {
          pcVar2 = pcVar1->dst;
        }
        else {
          pcVar2 = pcVar1->src;
        }
        for (; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
          switch(pcVar2->kind) {
          case '\x01':
          case '\x02':
          case '\x03':
            storage = pcVar2->sym->storage;
LAB_1071a376:
            if ((storage != (c2_symbol *)0x0) &&
               (iVar3 = param_list_contains(storage,params,0), iVar3 != 0)) {
              storage->fe->attrs = storage->fe->attrs | 0x100;
            }
            break;
          case '\x05':
          case '\x06':
            if (pcVar2->base_sym != (c2_symbol *)0x0) {
              storage = pcVar2->base_sym->storage;
              goto LAB_1071a376;
            }
          }
        }
        local_8 = local_8 + -1;
      } while (0 < local_8);
    }
    pcVar1 = pcVar1->next;
  } while( true );
}

