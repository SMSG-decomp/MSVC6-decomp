c2_cxx_catch * __fastcall
cxx_eh_new_catch_record
          (c2_cxx_try_block *try_block,uint32_t adjectives,c2_fe_symbol *type,c2_fe_symbol *object)

{
  char cVar1;
  c2_cxx_catch *pcVar2;
  int iVar3;
  c2_cxx_catch *pcVar4;
  c2_fe_symbol *pcVar5;
  char *pcVar6;
  uint uVar7;
  
  pcVar4 = arena_alloc(1,0x18);
  pcVar4->next = (c2_cxx_catch *)0x0;
  pcVar4->adjectives = adjectives;
  pcVar4->type = type;
  pcVar5 = label_symbol_new();
  iVar3 = g_opt_edit_and_continue;
  pcVar4->object = object;
  pcVar5->role = 'V';
  uVar7 = (pcVar5->u3e).label_flags;
  pcVar4->label = pcVar5;
  (pcVar5->u3e).label_flags = uVar7 | 1;
  if (iVar3 != 0) {
    uVar7 = 0xffffffff;
    pcVar6 = g_cur_function->fsym->name;
    do {
      if (uVar7 == 0) break;
      uVar7 = uVar7 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    pcVar6 = arena_alloc(0,~uVar7 + 0x14);
    iVar3 = g_eh_name_counter;
    g_eh_name_counter = g_eh_name_counter + 1;
    sprintf(pcVar6,"__catch$%s$%d",g_cur_function->fsym->name,iVar3);
    pcVar5->name = pcVar6;
  }
  if (try_block->ncatches == 0) {
    try_block->catches = pcVar4;
    try_block->ncatches = 1;
    (try_block->u24).catch_tail = pcVar4;
    return pcVar4;
  }
  pcVar2 = (try_block->u24).catch_tail;
  try_block->ncatches = try_block->ncatches + 1;
  (try_block->u24).catch_tail = pcVar4;
  pcVar2->next = pcVar4;
  return pcVar4;
}

