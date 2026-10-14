void __fastcall asm_print_memory_operand(c2_tuple *t,c2_operand *op,int size)

{
  uint32_t uVar1;
  int iVar2;
  int32_t disp;
  c2_symbol *pcVar3;
  char *fmt;
  char *printf_arg;
  
  asm_print_ptr_prefix(t,op,size);
  uVar1 = op->op;
  switch(uVar1) {
  case 0x146:
    iVar2 = asm_printf("%ld",(op->u18).reg);
    g_asm_column = g_asm_column + iVar2;
    return;
  case 0x147:
    iVar2 = asm_printf("%ld",op->sym->offset);
    g_asm_column = g_asm_column + iVar2;
    return;
  case 0x149:
    printf_arg = g_register_names[((op->u18).reg)->id];
    goto LAB_10774f23;
  case 0x14a:
    pcVar3 = op->sym;
    asm_print_storage_symbol(pcVar3);
    if (((g_esp_adjust_params == 0) || (pcVar3->cls != '\x05')) &&
       ((g_esp_adjust_locals == 0 || (pcVar3->cls == '\x05')))) {
      printf_arg = "[ebp";
    }
    else {
      printf_arg = "[esp";
    }
    iVar2 = asm_printf(printf_arg);
    g_asm_column = g_asm_column + iVar2;
    disp = (pcVar3->offset - pcVar3->storage->offset) - op->rank;
    goto LAB_10775239;
  case 0x14b:
    if (op->kind != '\x02') {
      iVar2 = asm_printf("OFFSET ");
      g_asm_column = g_asm_column + iVar2;
      if (g_opt_dos != 0) {
        iVar2 = asm_printf("FLAT:");
        g_asm_column = g_asm_column + iVar2;
      }
    }
    pcVar3 = op->sym;
    asm_print_storage_symbol(pcVar3);
    asm_print_displacement(pcVar3->offset - pcVar3->storage->offset,0);
    return;
  case 0x14c:
    pcVar3 = op->base_sym;
    asm_print_storage_symbol(pcVar3);
    printf_arg = g_register_names[((op->base->u18).reg)->id];
    fmt = "[%s";
LAB_1077520d:
    iVar2 = asm_printf(fmt,printf_arg);
    g_asm_column = g_asm_column + iVar2;
    break;
  default:
    pcVar3 = op->base_sym;
    asm_print_storage_symbol(pcVar3);
    iVar2 = asm_printf("[");
    g_asm_column = g_asm_column + iVar2;
    if (uVar1 == 0x14d) {
      iVar2 = asm_printf("%s",g_register_names[((op->base->u18).reg)->id]);
      g_asm_column = g_asm_column + iVar2;
      iVar2 = asm_printf("+%s",g_register_names[((op->index->u18).reg)->id]);
    }
    else {
      iVar2 = asm_printf("%s",g_register_names[((op->index->u18).reg)->id]);
    }
    g_asm_column = g_asm_column + iVar2;
    if ((op->flags & 0xf) != 0) {
      printf_arg = (char *)(1 << (op->flags & 0xf));
      fmt = "*%d";
      goto LAB_1077520d;
    }
    break;
  case 0x14e:
    pcVar3 = op->base_sym;
    asm_print_storage_symbol(pcVar3);
    if (((g_esp_adjust_params == 0) || (pcVar3->cls != '\x05')) &&
       ((g_esp_adjust_locals == 0 || (pcVar3->cls == '\x05')))) {
      printf_arg = "[ebp";
    }
    else {
      printf_arg = "[esp";
    }
    iVar2 = asm_printf(printf_arg);
    g_asm_column = g_asm_column + iVar2;
    disp = op->disp - op->rank;
    iVar2 = asm_printf("+%s",g_register_names[((op->index->u18).reg)->id]);
    g_asm_column = g_asm_column + iVar2;
    if ((op->flags & 0xf) != 0) {
      iVar2 = asm_printf("*%d",1 << (op->flags & 0xf));
      g_asm_column = g_asm_column + iVar2;
    }
    goto LAB_10775226;
  case 0x150:
    iVar2 = asm_printf("OFFSET ");
    g_asm_column = g_asm_column + iVar2;
    if (g_opt_dos != 0) {
      iVar2 = asm_printf("FLAT:");
      g_asm_column = g_asm_column + iVar2;
    }
    if (op->base_sym == (c2_symbol *)0x0) {
      iVar2 = asm_printf("$");
      g_asm_column = g_asm_column + iVar2;
      asm_print_displacement(op->disp,0);
      return;
    }
    asm_print_storage_symbol(op->base_sym);
    asm_print_displacement(op->disp,0);
    return;
  case 0x151:
    iVar2 = asm_printf("SEG ");
    g_asm_column = g_asm_column + iVar2;
    asm_print_storage_symbol(op->base_sym);
    asm_print_displacement(op->disp,0);
    return;
  case 0x152:
    if (op->base_sym == (c2_symbol *)0x0) {
      if ((op->flags11 & 7) == 0) {
        iVar2 = asm_printf("ds:");
        g_asm_column = g_asm_column + iVar2;
      }
      iVar2 = asm_printf("%ld",op->disp);
      g_asm_column = g_asm_column + iVar2;
      return;
    }
    asm_print_storage_symbol(op->base_sym);
    asm_print_displacement(op->disp,0);
    return;
  case 0x153:
    if (((op->sym->cls == '\x04') && (t->kind != '\x0e')) && (t->kind != '\x11')) {
      iVar2 = asm_printf("OFFSET ");
      g_asm_column = g_asm_column + iVar2;
      if (g_opt_dos != 0) {
        iVar2 = asm_printf("FLAT:");
        g_asm_column = g_asm_column + iVar2;
      }
    }
  case 0x154:
    asm_print_symbol_name(op->sym);
    return;
  case 0x156:
    if (op->disp != 0) {
      iVar2 = asm_printf("$+%d",op->disp);
      g_asm_column = g_asm_column + iVar2;
      return;
    }
    printf_arg = "$";
    goto LAB_10774f23;
  }
  disp = op->disp;
LAB_10775226:
  if (pcVar3 != (c2_symbol *)0x0) {
    disp = disp + (pcVar3->offset - pcVar3->storage->offset);
  }
LAB_10775239:
  asm_print_displacement(disp,0);
  printf_arg = "]";
LAB_10774f23:
  iVar2 = asm_printf(printf_arg);
  g_asm_column = g_asm_column + iVar2;
  return;
}

