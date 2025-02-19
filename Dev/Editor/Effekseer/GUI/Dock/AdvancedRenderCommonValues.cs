using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Effekseer.GUI.Dock
{
	class AdvancedRenderCommonValues : DockPanel
	{
		Component.ParameterList parameterList = null;

		bool isFirstUpdate = true;

		public AdvancedRenderCommonValues()
		{
			Label = Icons.PanelAdvancedRenderCommon + Resources.GetString("AdvancedRenderSettings") + "###AdvancedRenderSettings";
			DocPage = "rendererCommonAd.html";

			parameterList = new Component.ParameterList();
			parameterList.SetType(typeof(Data.AdvancedRenderCommonValues));

			CopyAndPaste = new Component.CopyAndPaste("AdvancedRenderSettings", GetTargetObject, Read);

			Core.OnAfterLoad += OnAfterLoad;
			Core.OnAfterNew += OnAfterLoad;
			Core.OnAfterSelectNode += OnAfterSelectNode;

			Controls.Add(parameterList);

			Read();

			TabToolTip = Resources.GetString("AdvancedRenderSettings");
		}

		public void FixValues()
		{
			parameterList.FixValues();
		}

		public override void OnDisposed()
		{
			FixValues();

			Core.OnAfterLoad -= OnAfterLoad;
			Core.OnAfterNew -= OnAfterLoad;
			Core.OnAfterSelectNode -= OnAfterSelectNode;
		}

		protected override void UpdateInternal()
		{
			if (isFirstUpdate)
			{
			}

			Manager.NativeManager.Separator();
		}

		object GetTargetObject()
		{
			if (Core.SelectedNode != null)
			{
				if (Core.SelectedNode is Data.Node)
				{
					return ((Data.Node)Core.SelectedNode).AdvancedRendererCommonValuesValues;
				}
			}
			return null;
		}

		void Read()
		{
			parameterList.SetValue(GetTargetObject());
		}

		void OnAfterLoad(object sender, EventArgs e)
		{
			Read();
		}

		void OnAfterSelectNode(object sender, EventArgs e)
		{
			Read();
		}
	}
}