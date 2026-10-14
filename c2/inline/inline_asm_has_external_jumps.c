int __fastcall inline_asm_has_external_jumps(c2_function *fn)

{
  c2_tuple *pcVar1;
  c2_tuple *target;
  c2_tuple *scan;
  c2_label_ref *ref_0;
  c2_tuple *asm_t;
  c2_tuple *asm_body;
  c2_label_ref *ref;
  
  pcVar1 = fn->cfg->first->head;
  do {
    if (pcVar1 == (c2_tuple *)0x0) {
      return 0;
    }
    if (pcVar1->op == 0x191) {
      asm_body = (pcVar1->u20).default_label;
      for (asm_t = asm_body; asm_t != (c2_tuple *)0x0; asm_t = asm_t->next) {
        if (asm_t->kind == '\x11') {
          if ((asm_t->src->kind != '\x04') ||
             (target = *(c2_tuple **)((int)&asm_t->src->sym->u30 + 2), scan = asm_body,
             target == (c2_tuple *)0x0)) {
            return 1;
          }
          while( true ) {
            if (scan == (c2_tuple *)0x0) {
              return 1;
            }
            if (scan == target) break;
            scan = scan->next;
          }
          if (scan == (c2_tuple *)0x0) {
            return 1;
          }
        }
        else if (asm_t->kind == '\x1a') {
          for (ref = (c2_label_ref *)asm_t->dst; ref != (c2_label_ref *)0x0; ref = ref->next) {
            if (asm_body == (c2_tuple *)0x0) {
              return 1;
            }
            target = asm_body;
            while (target != (c2_tuple *)ref->referrer) {
              target = target->next;
              if (target == (c2_tuple *)0x0) {
                return 1;
              }
            }
            if (target == (c2_tuple *)0x0) {
              return 1;
            }
          }
        }
      }
    }
    pcVar1 = pcVar1->next;
  } while( true );
}

