void __fastcall relax_init_sizes(c2_function *fn)

{
  char cVar1;
  c2_tuple *t;
  int iVar2;
  int saved_esp_adjust_locals;
  int saved_esp_adjust_params;
  
  saved_esp_adjust_locals = g_esp_adjust_locals;
  saved_esp_adjust_params = g_esp_adjust_params;
  t = fn->cfg->first->head;
  do {
    if (t == (c2_tuple *)0x0) {
      g_esp_adjust_params = saved_esp_adjust_params;
      g_esp_adjust_locals = saved_esp_adjust_locals;
      return;
    }
    if ((t->flags & 1) == 0) {
      if (t->kind == '\x1a') {
        t->flags12 = '\0';
        cVar1 = *(char *)&t->src[1].next;
        if ((cVar1 == 'T') || (cVar1 == 'U')) {
          g_esp_adjust_params = 0;
          g_esp_adjust_locals = 0;
        }
      }
    }
    else if (t->kind == '\x11') {
      if ((t->src->kind != '\x04') || (t->src->sym->cls != '\x03')) goto LAB_1073f352;
      if (t->op == 0xf) {
        t->op = 0x113;
        iVar2 = tuple_encoded_length(t);
        t->flags12 = (uint8_t)iVar2;
      }
      else {
        if (t->op != 0x10) goto LAB_1073f352;
        t->op = 0x115;
        iVar2 = tuple_encoded_length(t);
        t->flags12 = (uint8_t)iVar2;
      }
    }
    else if (t->op == 0xba) {
      t->op = 0xd;
      iVar2 = tuple_encoded_length(t);
      t->flags12 = (uint8_t)iVar2;
    }
    else {
      if (t->op == 0xb9) {
        t->op = 0xc;
      }
LAB_1073f352:
      iVar2 = tuple_encoded_length(t);
      t->flags12 = (uint8_t)iVar2;
    }
    t = t->next;
  } while( true );
}

