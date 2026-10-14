char __thiscall pdb_open_minimal_rebuild_engine(c1_pdb_state *state,c1_pdb_state *gi_state)

{
  MREngine *this;
  int iVar1;
  PDB *local_11c;
  NameMap *local_118;
  TPI *local_114;
  PDB *local_110;
  int mre_arg4;
  int mre_arg5;
  char local_104 [260];
  
  local_11c = state->pdb;
  local_118 = state->name_map;
  local_110 = gi_state->pdb;
  local_114 = gi_state->tpi;
  mre_arg4 = 0;
  mre_arg5 = 0;
  iVar1 = MREngine::FOpen((MREngine **)&state->mre,(MreToPdb *)&local_11c,1,0);
  if (iVar1 != 0) {
    this = state->mre;
    (*this->vtbl->QueryMreCmp)(this,&state->mre_driver,gi_state->tpi);
    return '\x01';
  }
  (*state->pdb->vtbl->QueryPDBName)(state->pdb,local_104);
  diag_error(0x1d7,local_104);
  return '\0';
}

