c2_cfg * __fastcall cfg_new(int arena)

{
  c2_cfg *cfg;
  
  cfg = arena_alloc(arena,0x34);
  cfg_init(cfg,arena,0x7c,0x14);
  return cfg;
}

