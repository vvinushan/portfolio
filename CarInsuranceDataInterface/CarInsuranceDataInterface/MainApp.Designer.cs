namespace CarInsuranceDataInterface
{
    partial class CIDI
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.titleBackground = new System.Windows.Forms.Panel();
            this.Title = new System.Windows.Forms.Label();
            this.HomeButtonPanel = new System.Windows.Forms.Panel();
            this.HomeButton = new System.Windows.Forms.Button();
            this.AllCustomersPanel = new System.Windows.Forms.Panel();
            this.AllCustomersButton = new System.Windows.Forms.Button();
            this.AddCustomerPanel = new System.Windows.Forms.Panel();
            this.AddCustomerButton = new System.Windows.Forms.Button();
            this.SearchCustomersPanel = new System.Windows.Forms.Panel();
            this.SearchCustomersButton = new System.Windows.Forms.Button();
            this.tableLayoutPanel1 = new System.Windows.Forms.TableLayoutPanel();
            this.TabPanel = new System.Windows.Forms.Panel();
            this.titleBackground.SuspendLayout();
            this.HomeButtonPanel.SuspendLayout();
            this.AllCustomersPanel.SuspendLayout();
            this.AddCustomerPanel.SuspendLayout();
            this.SearchCustomersPanel.SuspendLayout();
            this.tableLayoutPanel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // titleBackground
            // 
            this.titleBackground.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(192)))), ((int)(((byte)(0)))));
            this.titleBackground.Controls.Add(this.Title);
            this.titleBackground.Dock = System.Windows.Forms.DockStyle.Top;
            this.titleBackground.Location = new System.Drawing.Point(0, 0);
            this.titleBackground.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.titleBackground.Name = "titleBackground";
            this.titleBackground.Size = new System.Drawing.Size(2462, 100);
            this.titleBackground.TabIndex = 0;
            // 
            // Title
            // 
            this.Title.AutoSize = true;
            this.Title.Font = new System.Drawing.Font("Bahnschrift SemiBold", 20F, System.Drawing.FontStyle.Bold);
            this.Title.ForeColor = System.Drawing.Color.White;
            this.Title.Location = new System.Drawing.Point(0, 0);
            this.Title.Name = "Title";
            this.Title.Size = new System.Drawing.Size(898, 81);
            this.Title.TabIndex = 0;
            this.Title.Text = "Car Insurance Data Interface";
            // 
            // HomeButtonPanel
            // 
            this.HomeButtonPanel.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.HomeButtonPanel.Controls.Add(this.HomeButton);
            this.HomeButtonPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.HomeButtonPanel.Location = new System.Drawing.Point(5, 5);
            this.HomeButtonPanel.Margin = new System.Windows.Forms.Padding(5);
            this.HomeButtonPanel.Name = "HomeButtonPanel";
            this.HomeButtonPanel.Padding = new System.Windows.Forms.Padding(0, 0, 0, 10);
            this.HomeButtonPanel.Size = new System.Drawing.Size(605, 138);
            this.HomeButtonPanel.TabIndex = 0;
            // 
            // HomeButton
            // 
            this.HomeButton.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.HomeButton.Dock = System.Windows.Forms.DockStyle.Fill;
            this.HomeButton.FlatAppearance.BorderSize = 0;
            this.HomeButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.HomeButton.Font = new System.Drawing.Font("Bahnschrift SemiBold", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.HomeButton.Location = new System.Drawing.Point(0, 0);
            this.HomeButton.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.HomeButton.Name = "HomeButton";
            this.HomeButton.Size = new System.Drawing.Size(605, 128);
            this.HomeButton.TabIndex = 1;
            this.HomeButton.Text = "Home";
            this.HomeButton.UseVisualStyleBackColor = false;
            this.HomeButton.Click += new System.EventHandler(this.HomeButton_Click);
            // 
            // AllCustomersPanel
            // 
            this.AllCustomersPanel.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.AllCustomersPanel.Controls.Add(this.AllCustomersButton);
            this.AllCustomersPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.AllCustomersPanel.Location = new System.Drawing.Point(620, 5);
            this.AllCustomersPanel.Margin = new System.Windows.Forms.Padding(5);
            this.AllCustomersPanel.Name = "AllCustomersPanel";
            this.AllCustomersPanel.Padding = new System.Windows.Forms.Padding(0, 0, 0, 10);
            this.AllCustomersPanel.Size = new System.Drawing.Size(605, 138);
            this.AllCustomersPanel.TabIndex = 1;
            // 
            // AllCustomersButton
            // 
            this.AllCustomersButton.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.AllCustomersButton.Dock = System.Windows.Forms.DockStyle.Fill;
            this.AllCustomersButton.FlatAppearance.BorderSize = 0;
            this.AllCustomersButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.AllCustomersButton.Font = new System.Drawing.Font("Bahnschrift SemiBold", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.AllCustomersButton.Location = new System.Drawing.Point(0, 0);
            this.AllCustomersButton.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.AllCustomersButton.Name = "AllCustomersButton";
            this.AllCustomersButton.Size = new System.Drawing.Size(605, 128);
            this.AllCustomersButton.TabIndex = 1;
            this.AllCustomersButton.Text = "All Customers";
            this.AllCustomersButton.UseVisualStyleBackColor = false;
            this.AllCustomersButton.Click += new System.EventHandler(this.AllCustomersButton_Click);
            // 
            // AddCustomerPanel
            // 
            this.AddCustomerPanel.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.AddCustomerPanel.Controls.Add(this.AddCustomerButton);
            this.AddCustomerPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.AddCustomerPanel.Location = new System.Drawing.Point(1235, 5);
            this.AddCustomerPanel.Margin = new System.Windows.Forms.Padding(5);
            this.AddCustomerPanel.Name = "AddCustomerPanel";
            this.AddCustomerPanel.Padding = new System.Windows.Forms.Padding(0, 0, 0, 10);
            this.AddCustomerPanel.Size = new System.Drawing.Size(605, 138);
            this.AddCustomerPanel.TabIndex = 2;
            // 
            // AddCustomerButton
            // 
            this.AddCustomerButton.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.AddCustomerButton.Dock = System.Windows.Forms.DockStyle.Fill;
            this.AddCustomerButton.FlatAppearance.BorderSize = 0;
            this.AddCustomerButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.AddCustomerButton.Font = new System.Drawing.Font("Bahnschrift SemiBold", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.AddCustomerButton.Location = new System.Drawing.Point(0, 0);
            this.AddCustomerButton.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.AddCustomerButton.Name = "AddCustomerButton";
            this.AddCustomerButton.Size = new System.Drawing.Size(605, 128);
            this.AddCustomerButton.TabIndex = 1;
            this.AddCustomerButton.Text = "Add Customer";
            this.AddCustomerButton.UseVisualStyleBackColor = false;
            this.AddCustomerButton.Click += new System.EventHandler(this.AddCustomerButton_Click);
            // 
            // SearchCustomersPanel
            // 
            this.SearchCustomersPanel.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.SearchCustomersPanel.Controls.Add(this.SearchCustomersButton);
            this.SearchCustomersPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.SearchCustomersPanel.Location = new System.Drawing.Point(1850, 5);
            this.SearchCustomersPanel.Margin = new System.Windows.Forms.Padding(5);
            this.SearchCustomersPanel.Name = "SearchCustomersPanel";
            this.SearchCustomersPanel.Padding = new System.Windows.Forms.Padding(0, 0, 0, 10);
            this.SearchCustomersPanel.Size = new System.Drawing.Size(607, 138);
            this.SearchCustomersPanel.TabIndex = 3;
            // 
            // SearchCustomersButton
            // 
            this.SearchCustomersButton.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.SearchCustomersButton.Dock = System.Windows.Forms.DockStyle.Fill;
            this.SearchCustomersButton.FlatAppearance.BorderSize = 0;
            this.SearchCustomersButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.SearchCustomersButton.Font = new System.Drawing.Font("Bahnschrift SemiBold", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.SearchCustomersButton.Location = new System.Drawing.Point(0, 0);
            this.SearchCustomersButton.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.SearchCustomersButton.Name = "SearchCustomersButton";
            this.SearchCustomersButton.Size = new System.Drawing.Size(607, 128);
            this.SearchCustomersButton.TabIndex = 1;
            this.SearchCustomersButton.Text = "Search Customers";
            this.SearchCustomersButton.UseVisualStyleBackColor = false;
            this.SearchCustomersButton.Click += new System.EventHandler(this.SearchCustomersButton_Click);
            // 
            // tableLayoutPanel1
            // 
            this.tableLayoutPanel1.BackColor = System.Drawing.SystemColors.ButtonShadow;
            this.tableLayoutPanel1.ColumnCount = 4;
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.tableLayoutPanel1.Controls.Add(this.SearchCustomersPanel, 3, 0);
            this.tableLayoutPanel1.Controls.Add(this.AddCustomerPanel, 2, 0);
            this.tableLayoutPanel1.Controls.Add(this.AllCustomersPanel, 1, 0);
            this.tableLayoutPanel1.Controls.Add(this.HomeButtonPanel, 0, 0);
            this.tableLayoutPanel1.Dock = System.Windows.Forms.DockStyle.Top;
            this.tableLayoutPanel1.Location = new System.Drawing.Point(0, 100);
            this.tableLayoutPanel1.Margin = new System.Windows.Forms.Padding(0);
            this.tableLayoutPanel1.Name = "tableLayoutPanel1";
            this.tableLayoutPanel1.RowCount = 1;
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.tableLayoutPanel1.Size = new System.Drawing.Size(2462, 148);
            this.tableLayoutPanel1.TabIndex = 1;
            // 
            // TabPanel
            // 
            this.TabPanel.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.TabPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.TabPanel.Location = new System.Drawing.Point(0, 248);
            this.TabPanel.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.TabPanel.Name = "TabPanel";
            this.TabPanel.Size = new System.Drawing.Size(2462, 763);
            this.TabPanel.TabIndex = 2;
            // 
            // CIDI
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(16F, 31F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(2462, 1011);
            this.Controls.Add(this.TabPanel);
            this.Controls.Add(this.tableLayoutPanel1);
            this.Controls.Add(this.titleBackground);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.Fixed3D;
            this.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.MaximizeBox = false;
            this.Name = "CIDI";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Car Insurance Data Interface";
            this.titleBackground.ResumeLayout(false);
            this.titleBackground.PerformLayout();
            this.HomeButtonPanel.ResumeLayout(false);
            this.AllCustomersPanel.ResumeLayout(false);
            this.AddCustomerPanel.ResumeLayout(false);
            this.SearchCustomersPanel.ResumeLayout(false);
            this.tableLayoutPanel1.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel titleBackground;
        private System.Windows.Forms.Label Title;
        private System.Windows.Forms.Panel HomeButtonPanel;
        private System.Windows.Forms.Button HomeButton;
        private System.Windows.Forms.Panel AllCustomersPanel;
        private System.Windows.Forms.Button AllCustomersButton;
        private System.Windows.Forms.Panel AddCustomerPanel;
        private System.Windows.Forms.Button AddCustomerButton;
        private System.Windows.Forms.Panel SearchCustomersPanel;
        private System.Windows.Forms.Button SearchCustomersButton;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel1;
        private System.Windows.Forms.Panel TabPanel;
    }
}

