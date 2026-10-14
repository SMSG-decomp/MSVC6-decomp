int __fastcall pdb_il_pending_add(char *module_name)

{
  c2_pdb_il_pending *pcVar1;
  
  pcVar1 = malloc(8);
  pcVar1->module_name = module_name;
  pcVar1->next = g_pdb_il_pending_modules;
  g_pdb_il_pending_modules = pcVar1;
  g_pdb_il_module_count = g_pdb_il_module_count + 1;
  return 1;
}

