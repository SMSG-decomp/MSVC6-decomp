void __fastcall section_set_defaults(c2_fe_symbol *sec)

{
  char *pcVar1;
  
  pcVar1 = g_section_default_class;
  (sec->u3e).label_flags = g_default_stack_align;
  sec->combine = '\x02';
  sec->section_id = (uint32_t)pcVar1;
  return;
}

