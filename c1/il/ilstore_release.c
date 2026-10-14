void ilstore_release(void)

{
  (*g_ilstore->vtbl->Release)(g_ilstore);
  g_ilstore = (ILStore *)0x0;
  g_ilstore_pdb = (PDB *)0x0;
  return;
}

