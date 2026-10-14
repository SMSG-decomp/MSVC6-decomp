c2_fe_symbol * __fastcall cor_helper_symbol(c2_fe_symbol *s,int is_def)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  uint32_t uVar4;
  uint uVar5;
  c2_fe_symbol *pcVar6;
  char *pcVar7;
  uint32_t uVar8;
  char local_65;
  char local_64 [100];
  
  local_65 = '\0';
  if (is_def == 0) {
    uVar8 = s->coff_section;
  }
  else {
    uVar8 = s->x77;
  }
  sprintf(local_64,"__cor_%s_%X",g_cor_helper_kind_names[(char)(s->u4a).function.cor_type],uVar8);
  bVar1 = s->flags31;
  if (is_def == 0) {
    pcVar6 = fe_symbol_lookup_name(local_64);
  }
  else {
    pcVar6 = fe_symbol_lookup_name(&local_65);
    pcVar7 = arena_strdup(local_64,0);
    pcVar6->name = pcVar7;
  }
  bVar2 = s->flags31;
  uVar4 = s->attrs;
  (pcVar6->u4a).function.x4b = s;
  bVar3 = pcVar6->flags31;
  (pcVar6->u4a).function.cor_type = (s->u4a).function.cor_type;
  uVar5 = pcVar6->storage;
  s->flags31 = (bVar2 ^ bVar1 & 1) & 1 ^ bVar2;
  pcVar6->attrs = uVar4;
  pcVar6->storage = uVar5 & 0xffffff4f | 0x40;
  pcVar6->coff_section = uVar8;
  pcVar6->flags31 = bVar3 & 0xfe;
  return pcVar6;
}

